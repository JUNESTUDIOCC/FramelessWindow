#include "CFramelessWindow.h"
#include <QGraphicsDropShadowEffect>
#include <QVBoxLayout>
#include <QMouseEvent>

#define HANLE_WIDTH		20

enum PosType
{
	PT_CONTENT,
	PT_LEFT,
	PT_TOP,
	PT_RIGHT,
	PT_BOTTOM,
	PT_LEFT_TOP,
	PT_TOP_RIGHT,
	PT_RIGHT_BOTTOM,
	PT_BOTTOM_LEFT
};


struct CFramelessWindowPrivate
{
	CFramelessWindowPrivate(QWidget* contentWidget)
	:m_contentWidget(contentWidget),
	m_blurRadius(12),
	m_widgetRadius(5),
	m_backgroundColor(Qt::white),
	m_shadowColor(Qt::black),
	m_dragEnabled(true),
	m_resizeEnabled(true)
	{
	
	}

	QWidget*	m_contentWidget;
	QPoint		m_pressedPost;
	QPoint		m_dragPos;
	PosType		m_posType;
	int			m_blurRadius;
	int			m_widgetRadius;
	QColor		m_backgroundColor;
	QColor		m_shadowColor;
	bool		m_dragEnabled;
	bool		m_resizeEnabled;
};


CFramelessWindow::CFramelessWindow(QWidget* contentWidget,QWidget* parent/*=0*/)
:QWidget(parent),
m_d(new CFramelessWindowPrivate(contentWidget))
{
	setAttribute(Qt::WA_StyledBackground, true);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowFlags(Qt::FramelessWindowHint);
	setMouseTracking(true);

	contentWidget->setAttribute(Qt::WA_StyledBackground, true);
	contentWidget->installEventFilter(this);
	contentWidget->setMouseTracking(true);

	QGraphicsDropShadowEffect* shadowEft = new QGraphicsDropShadowEffect(contentWidget);
	shadowEft->setColor(m_d->m_shadowColor);
	shadowEft->setBlurRadius(m_d->m_blurRadius);
	shadowEft->setOffset(0.0);
	contentWidget->setGraphicsEffect(shadowEft);

	QVBoxLayout* ly = new QVBoxLayout();
	ly->addWidget(contentWidget);
	ly->setContentsMargins(m_d->m_blurRadius, m_d->m_blurRadius, m_d->m_blurRadius, m_d->m_blurRadius);
	setLayout(ly);

	contentWidget->setObjectName("CFramelessWindow_contentWidget");
}

CFramelessWindow::~CFramelessWindow()
{
	delete m_d;
}

void CFramelessWindow::SetBlurRadius(int radius)
{
	m_d->m_blurRadius = radius;
}

void CFramelessWindow::SetWidgetRadius(int radius)
{
	m_d->m_widgetRadius = radius;
	Update();
}

void CFramelessWindow::SetShadowColor(const QColor &color)
{
	m_d->m_shadowColor = color;
}


void CFramelessWindow::SetBackgroundColor(const QColor &color)
{
	m_d->m_backgroundColor = color;
	Update();
}

void CFramelessWindow::SetDragEnabled(bool dragEnabled)
{
	m_d->m_dragEnabled = dragEnabled;
}

void CFramelessWindow::SetResizeEnabled(bool resizeEnabled)
{
	m_d->m_resizeEnabled = resizeEnabled;
}

void CFramelessWindow::mousePressEvent(QMouseEvent *event)
{
	m_d->m_pressedPost = event->globalPos();
	m_d->m_dragPos = pos();
}

void CFramelessWindow::mouseMoveEvent(QMouseEvent *event)
{
	QPoint currentPost = event->pos();
	m_d->m_posType = static_cast<PosType>(GetPosType(currentPost));
	
	if (m_d->m_resizeEnabled)
	{
		switch (m_d->m_posType)
		{
		case PT_LEFT:
		case PT_RIGHT:
			setCursor(Qt::SizeHorCursor);
			break;
		case PT_TOP:
		case PT_BOTTOM:
			setCursor(Qt::SizeVerCursor);
			break;
		case PT_LEFT_TOP:
		case PT_RIGHT_BOTTOM:
			setCursor(Qt::SizeFDiagCursor);
			break;
		case PT_BOTTOM_LEFT:
		case PT_TOP_RIGHT:
			setCursor(Qt::SizeBDiagCursor);
			break;
		default:
			setCursor(Qt::ArrowCursor);
			break;
		}
	}



	if (!m_d->m_pressedPost.isNull())
	{
		//ÒÆ¶¯
		if (m_d->m_posType == PT_CONTENT)
		{
			if (m_d->m_dragEnabled)
			{
				QPoint delta = event->globalPos() - m_d->m_pressedPost;
				move(m_d->m_dragPos + delta);
			}
		}
		else//Ëõ·Å
		{
			if (m_d->m_resizeEnabled)
			{
				QRect rc = geometry();
				QPoint dest = event->globalPos();
				switch (m_d->m_posType)
				{
				case PT_LEFT:
					rc.setLeft(dest.x());
					break;
				case PT_TOP:
					rc.setTop(dest.y());
					break;
				case PT_RIGHT:
					rc.setRight(dest.x());
					break;
				case PT_BOTTOM:
					rc.setBottom(dest.y());
					break;
				case PT_LEFT_TOP:
					rc.setTopLeft(dest);
					break;
				case PT_TOP_RIGHT:
					rc.setTopRight(dest);
					break;
				case PT_RIGHT_BOTTOM:
					rc.setBottomRight(dest);
					break;
				case PT_BOTTOM_LEFT:
					rc.setBottomLeft(dest);
					break;
				default:
					break;
				}
				setGeometry(rc);
			}
		}
	}
}

void CFramelessWindow::mouseReleaseEvent(QMouseEvent *event)
{
	Q_UNUSED(event);
	m_d->m_pressedPost = QPoint();
}

bool CFramelessWindow::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == m_d->m_contentWidget)
	{
		int t = event->type();
		if (t == QEvent::MouseMove)
		{
			QMouseEvent* me = dynamic_cast<QMouseEvent*>(event);
			if (me)
			{
				mouseMoveEvent(me);
			}
			return false;
		}
		else if (t == QEvent::MouseButtonPress)
		{
			QMouseEvent* me = dynamic_cast<QMouseEvent*>(event);
			if (me)
			{
				mousePressEvent(me);
			}
			return false;
		}
		else if (t == QEvent::MouseButtonRelease)
		{
			QMouseEvent* me = dynamic_cast<QMouseEvent*>(event);
			if (me)
			{
				mouseReleaseEvent(me);
			}
			return false;
		}
		else
		{
			return QWidget::eventFilter(watched, event);
		}
	}
	else
	{
		return QWidget::eventFilter(watched, event);
	}
}
 
int CFramelessWindow::GetPosType(const QPoint& pt)
{
	if (!m_d->m_pressedPost.isNull())
	{
		return m_d->m_posType;
	}
	if (pt.x()<HANLE_WIDTH&&pt.y()>HANLE_WIDTH&&pt.y() < height() - HANLE_WIDTH)
	{
		return PT_LEFT;
	}
	else if (pt.x()>HANLE_WIDTH&&pt.y() < HANLE_WIDTH&&pt.x() < width() - HANLE_WIDTH)
	{
		return PT_TOP;
	}
	else if (pt.y()>HANLE_WIDTH&&pt.y()<height() - HANLE_WIDTH&&pt.x()>width() - HANLE_WIDTH)
	{
		return PT_RIGHT;
	}
	else if (pt.y()>height() - HANLE_WIDTH&&pt.x() > HANLE_WIDTH&&pt.x() < width() - HANLE_WIDTH)
	{
		return PT_BOTTOM;
	}
	else if (pt.x() < HANLE_WIDTH&&pt.y() < HANLE_WIDTH)
	{
		return PT_LEFT_TOP;
	}
	else if (pt.x()>width() - HANLE_WIDTH&&pt.y() < HANLE_WIDTH)
	{
		return PT_TOP_RIGHT;
	}
	else if (pt.x()<HANLE_WIDTH&&pt.y()>height() - HANLE_WIDTH)
	{
		return PT_BOTTOM_LEFT;
	}
	else if (pt.x()>width() - HANLE_WIDTH&&pt.y() > height() - HANLE_WIDTH)
	{
		return PT_RIGHT_BOTTOM;
	}
	else
	{
		return PT_CONTENT;
	}
}

void CFramelessWindow::Update()
{
	QString text = QString("#CFramelessWindow_contentWidget{border-radius:%1px;background:rgba(%2,%3,%4,%5);}")
		.arg(m_d->m_widgetRadius)
		.arg(m_d->m_backgroundColor.red())
		.arg(m_d->m_backgroundColor.green())
		.arg(m_d->m_backgroundColor.blue())
		.arg(m_d->m_backgroundColor.alpha());
	m_d->m_contentWidget->setStyleSheet(text);
}
