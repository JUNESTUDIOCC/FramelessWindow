#include "CFramelessWindow.h"
#include <QGraphicsDropShadowEffect>
#include <QGridLayout>
#include <QMouseEvent>

#define HANLE_WIDTH		20

struct CFramelessWindowPrivate
{
	CFramelessWindowPrivate(QWidget* contentWidget)
	:m_contentWidget(contentWidget){}

	QWidget*	m_contentWidget;
	QPoint		m_pressedPost;
	QPoint		m_dragPos;
	PosType		m_posType;
};


CFramelessWindow::CFramelessWindow(QWidget* contentWidget,QWidget* parent/*=0*/)
:QWidget(parent)
{
	setAttribute(Qt::WA_StyledBackground, true);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowFlags(Qt::FramelessWindowHint);
	setMouseTracking(true);

	contentWidget->setAttribute(Qt::WA_StyledBackground, true);
	contentWidget->installEventFilter(this);
	contentWidget->setMouseTracking(true);

	m_d = new CFramelessWindowPrivate(contentWidget);

	QGraphicsDropShadowEffect* shadowEft = new QGraphicsDropShadowEffect(contentWidget);
	shadowEft->setColor(Qt::black);
	shadowEft->setBlurRadius(5);
	shadowEft->setOffset(0.0);
	contentWidget->setGraphicsEffect(shadowEft);

	QGridLayout* ly = new QGridLayout();
	ly->addWidget(contentWidget);
	ly->setContentsMargins(4, 4, 4, 4);
	setLayout(ly);

	contentWidget->setObjectName("contentWidget");
	contentWidget->setStyleSheet("#contentWidget{background:rgba(80,80,80,200);border-radius:4px;}");
}

CFramelessWindow::~CFramelessWindow()
{

}

void CFramelessWindow::mousePressEvent(QMouseEvent *event)
{
	m_d->m_pressedPost = event->globalPos();
	m_d->m_dragPos = pos();
}

void CFramelessWindow::mouseMoveEvent(QMouseEvent *event)
{
	QPoint currentPost = event->pos();
	m_d->m_posType = GetPosType(currentPost);
	if (!m_d->m_pressedPost.isNull())
	{
		//ÒÆ¶¯
		if (m_d->m_posType == PT_CONTENT)
		{
			QPoint delta = event->globalPos() - m_d->m_pressedPost;
			move(m_d->m_dragPos + delta);
		}
		else//Ëõ·Å
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
 
PosType CFramelessWindow::GetPosType(const QPoint& pt)
{
	if (!m_d->m_pressedPost.isNull())
	{
		return m_d->m_posType;
	}
	if (pt.x()<HANLE_WIDTH&&pt.y()>HANLE_WIDTH&&pt.y() < height() - HANLE_WIDTH)
	{
		setCursor(Qt::SizeHorCursor);
		return PT_LEFT;
	}
	else if (pt.x()>HANLE_WIDTH&&pt.y() < HANLE_WIDTH&&pt.x() < width() - HANLE_WIDTH)
	{
		setCursor(Qt::SizeVerCursor);
		return PT_TOP;
	}
	else if (pt.y()>HANLE_WIDTH&&pt.y()<height() - HANLE_WIDTH&&pt.x()>width() - HANLE_WIDTH)
	{
		setCursor(Qt::SizeHorCursor);
		return PT_RIGHT;
	}
	else if (pt.y()>height() - HANLE_WIDTH&&pt.x() > HANLE_WIDTH&&pt.x() < width() - HANLE_WIDTH)
	{
		setCursor(Qt::SizeVerCursor);
		return PT_BOTTOM;
	}
	else if (pt.x() < HANLE_WIDTH&&pt.y() < HANLE_WIDTH)
	{
		setCursor(Qt::SizeFDiagCursor);
		return PT_LEFT_TOP;
	}
	else if (pt.x()>width() - HANLE_WIDTH&&pt.y() < HANLE_WIDTH)
	{
		setCursor(Qt::SizeBDiagCursor);
		return PT_TOP_RIGHT;
	}
	else if (pt.x()<HANLE_WIDTH&&pt.y()>height() - HANLE_WIDTH)
	{
		setCursor(Qt::SizeBDiagCursor);
		return PT_BOTTOM_LEFT;
	}
	else if (pt.x()>width() - HANLE_WIDTH&&pt.y() > height() - HANLE_WIDTH)
	{
		setCursor(Qt::SizeFDiagCursor);
		return PT_RIGHT_BOTTOM;
	}
	else
	{
		setCursor(Qt::ArrowCursor);
		return PT_CONTENT;
	}
}
