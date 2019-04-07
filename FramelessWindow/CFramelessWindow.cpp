#include "CFramelessWindow.h"
#include <QGraphicsDropShadowEffect>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QPainter>

#define HANLE_WIDTH		10

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
	CFramelessWindowPrivate()
	:m_blurRadius(12),
	m_widgetRadius(5),
	m_backgroundColor(Qt::white),
	m_shadowColor(Qt::black),
	m_dragEnabled(true),
	m_resizeEnabled(true)
	{
	
	}

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

CFramelessWindow::CFramelessWindow(QWidget* parent/*=0*/)
:QWidget(parent),
m_d(new CFramelessWindowPrivate())
{
	setAttribute(Qt::WA_StyledBackground);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setMouseTracking(true);

	QGraphicsDropShadowEffect* shadowEft = new QGraphicsDropShadowEffect(this);
	shadowEft->setOffset(0.0);
	shadowEft->setColor(m_d->m_shadowColor);
	shadowEft->setBlurRadius(m_d->m_blurRadius);
	setGraphicsEffect(shadowEft);

	QVBoxLayout* ly = new QVBoxLayout();
	ly->setContentsMargins(m_d->m_blurRadius, m_d->m_blurRadius, m_d->m_blurRadius, m_d->m_blurRadius);
	setLayout(ly);
}

CFramelessWindow::~CFramelessWindow()
{
	delete m_d;
}

int CFramelessWindow::GetBlurRadius()
{
	return m_d->m_blurRadius;
}

int CFramelessWindow::GetWidgetRadius()
{
	return m_d->m_widgetRadius;
}

const QColor& CFramelessWindow::GetShadowColor()
{
	return m_d->m_shadowColor;
}

const QColor& CFramelessWindow::GetBackgroundColor()
{
	return m_d->m_backgroundColor;
}

bool CFramelessWindow::GetDragEnabled()
{
	return m_d->m_dragEnabled;
}

bool CFramelessWindow::GetResizeEnabled()
{
	return m_d->m_resizeEnabled;
}

void CFramelessWindow::SetBlurRadius(int radius)
{
	m_d->m_blurRadius = radius;
}

void CFramelessWindow::SetWidgetRadius(int radius)
{
	m_d->m_widgetRadius = radius;
}

void CFramelessWindow::SetShadowColor(const QColor &color)
{
	m_d->m_shadowColor = color;
}


void CFramelessWindow::SetBackgroundColor(const QColor &color)
{
	m_d->m_backgroundColor = color;
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
				QRect tmRc;
				QRect rc = geometry();
				
				QPoint dest = event->globalPos();

				switch (m_d->m_posType)
				{
				case PT_LEFT:
					rc.setLeft(dest.x()-m_d->m_blurRadius);
					if (rc.width() < minimumWidth())
						return;
					break;
				case PT_TOP:
					rc.setTop(dest.y() - m_d->m_blurRadius);
					if (rc.height() < minimumHeight())
						return;
					break;
				case PT_RIGHT:
					rc.setRight(dest.x() + m_d->m_blurRadius);
					break;
				case PT_BOTTOM:
					rc.setBottom(dest.y() + m_d->m_blurRadius);
					break;
				case PT_LEFT_TOP:
					tmRc = rc;
					tmRc.setTopLeft(dest - QPoint(m_d->m_blurRadius, m_d->m_blurRadius));
					if (tmRc.width() >= minimumWidth())
					{
						rc.setLeft(dest.x() - m_d->m_blurRadius);
					}
					if (tmRc.height() >= minimumHeight())
					{
						rc.setTop(dest.y() - m_d->m_blurRadius);
					}
					break;
				case PT_TOP_RIGHT:
					tmRc = rc;
					tmRc.setTopRight(dest - QPoint(-m_d->m_blurRadius, m_d->m_blurRadius));
					if (tmRc.height() >= minimumHeight())
					{
						rc.setTop(dest.y() - m_d->m_blurRadius);
					}
					rc.setRight(dest.x() + m_d->m_blurRadius);

					break;
				case PT_RIGHT_BOTTOM:
					tmRc = rc;
					tmRc.setBottomRight(dest + QPoint(m_d->m_blurRadius, m_d->m_blurRadius));
					if (tmRc.width() >= minimumWidth())
					{
						rc.setRight(dest.x() + m_d->m_blurRadius);
					}
					rc.setBottom(dest.y() + m_d->m_blurRadius);
					break;
				case PT_BOTTOM_LEFT:
					tmRc = rc;
					tmRc.setBottomLeft(dest - QPoint(m_d->m_blurRadius, -m_d->m_blurRadius));
					if (tmRc.width() >= minimumWidth())
					{
						rc.setLeft(dest.x() - m_d->m_blurRadius);
					}
					rc.setBottom(dest.y() + m_d->m_blurRadius);
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
 
void CFramelessWindow::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(Qt::NoPen);
	painter.setBrush(m_d->m_backgroundColor);

	int w = this->width()-2*m_d->m_blurRadius;
	int h = this->height() - 2*m_d->m_blurRadius;

	painter.drawRoundedRect(m_d->m_blurRadius, m_d->m_blurRadius, w, h, m_d->m_widgetRadius, m_d->m_widgetRadius);
}

int CFramelessWindow::GetPosType(const QPoint& pt)
{
	if (!m_d->m_pressedPost.isNull())
	{
		return m_d->m_posType;
	}

	int leftTop = m_d->m_blurRadius + HANLE_WIDTH;
	int bottomY = height() - m_d->m_blurRadius - HANLE_WIDTH;
	int rightX = width() - m_d->m_blurRadius - HANLE_WIDTH;
	
	if (pt.x()<leftTop&&pt.y()>leftTop&&pt.y() < bottomY)
	{
		return PT_LEFT;
	}
	else if (pt.x()>leftTop&&pt.y() < leftTop&&pt.x() < rightX)
	{
		return PT_TOP;
	}
	else if (pt.y()>leftTop&&pt.y()<bottomY&&pt.x()>rightX)
	{
		return PT_RIGHT;
	}
	else if (pt.y()>bottomY&&pt.x() > leftTop&&pt.x() < rightX)
	{
		return PT_BOTTOM;
	}
	else if (pt.x() < leftTop&&pt.y() < leftTop)
	{
		return PT_LEFT_TOP;
	}
	else if (pt.x()>rightX&&pt.y() < leftTop)
	{
		return PT_TOP_RIGHT;
	}
	else if (pt.x()<leftTop&&pt.y()>bottomY)
	{
		return PT_BOTTOM_LEFT;
	}
	else if (pt.x()>rightX&&pt.y() > bottomY)
	{
		return PT_RIGHT_BOTTOM;
	}
	else
	{
		return PT_CONTENT;
	}
}

