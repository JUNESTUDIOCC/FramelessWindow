#include "CPopupWidget.h"
#include <QPainter>
#include <QCoreApplication>

#define TRIANGLE_WIDTH  10               // 小三角的宽度;
#define TRIANGLE_HEIGHT 15               // 小三角的高度;

CPopupWidget::CPopupWidget(QWidget* parent /*= 0*/)
:CFramelessWindow(parent),
m_arrowDirction(AD_RIGHT),
m_top(50)
{
	setWindowFlags(windowFlags() | Qt::Window);
	SetDragEnabled(false);
	SetResizeEnabled(false);
}

CPopupWidget::~CPopupWidget()
{

}

void CPopupWidget::SetArrowDirection(ArrowDirection arrowDirction)
{
	m_arrowDirction = arrowDirction;
}

void CPopupWidget::Show(int x, int y)
{
	int arrowX, arrowY;
	switch (m_arrowDirction)
	{
	case AD_UP:
		arrowX = x - m_top;
		arrowY = y-GetBlurRadius();
		break;
	case AD_DOWN:
		arrowX = x - width() + m_top;
		arrowY = y - height() + GetBlurRadius();
		break;
	case AD_LEFT:
		arrowX = x - GetBlurRadius();
		arrowY = y -height()+ m_top;
		break;
	case AD_RIGHT:
		arrowX = x - width()+GetBlurRadius();
		arrowY = y - m_top;
		break;
	}
	move(arrowX, arrowY);
	show();
}

void CPopupWidget::Show(const QPoint& pt)
{
	Show(pt.x(), pt.y());
}

void CPopupWidget::SetTop(int top)
{
	m_top = top;
}

void CPopupWidget::Resize(int w, int h)
{
	resize(w + GetBlurRadius(), h);
}

void CPopupWidget::paintEvent(QPaintEvent *event)
{
	QPainterPath drawPath;
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(Qt::NoPen);
	painter.setBrush(GetBackgroundColor());

	int w, h, x, y, radius;
	radius = GetWidgetRadius();

	QPolygon trianglePolygon;
	switch (m_arrowDirction)
	{
	case AD_UP:
		w = this->width() - 2 * GetBlurRadius();
		h = this->height() - 2 * GetBlurRadius() - TRIANGLE_HEIGHT;
		x = GetBlurRadius();
		y = GetBlurRadius() + TRIANGLE_HEIGHT;
		drawPath.addRoundedRect(x, y, w, h, radius, radius);

		trianglePolygon << QPoint(m_top - TRIANGLE_WIDTH, y);
		trianglePolygon << QPoint(m_top, GetBlurRadius());
		trianglePolygon << QPoint(m_top + TRIANGLE_WIDTH, y);
		drawPath.addPolygon(trianglePolygon);

		break;
	case AD_DOWN:
		w = this->width() - 2 * GetBlurRadius();
		h = this->height() - 2 * GetBlurRadius() - TRIANGLE_HEIGHT;
		x = GetBlurRadius();
		y = GetBlurRadius();
		drawPath.addRoundedRect(x, y, w, h, radius, radius);

		trianglePolygon << QPoint(width()-m_top - TRIANGLE_WIDTH, height()-GetBlurRadius() - TRIANGLE_HEIGHT);
		trianglePolygon << QPoint(width() - m_top, height()-GetBlurRadius());
		trianglePolygon << QPoint(width() - m_top + TRIANGLE_WIDTH, height() - GetBlurRadius() - TRIANGLE_HEIGHT);
		drawPath.addPolygon(trianglePolygon);

		break;
	case AD_LEFT:
		w = this->width() - 2 * GetBlurRadius() - TRIANGLE_HEIGHT;
		h = this->height() - 2 * GetBlurRadius();
		x = GetBlurRadius() + TRIANGLE_HEIGHT;
		y = GetBlurRadius();
		drawPath.addRoundedRect(x, y, w, h, radius, radius);

		trianglePolygon << QPoint(GetBlurRadius() + TRIANGLE_HEIGHT, height()-m_top - TRIANGLE_WIDTH);
		trianglePolygon << QPoint(GetBlurRadius(), height()-m_top);
		trianglePolygon << QPoint(GetBlurRadius() + TRIANGLE_HEIGHT, height() - m_top + TRIANGLE_WIDTH);
		drawPath.addPolygon(trianglePolygon);
		break;
	case AD_RIGHT:
		w = this->width() - 2 * GetBlurRadius() - TRIANGLE_HEIGHT;
		h = this->height() - 2 * GetBlurRadius();
		x = GetBlurRadius();
		y = GetBlurRadius();
		drawPath.addRoundedRect(x, y, w, h, radius, radius);

		trianglePolygon << QPoint(x + w, m_top - TRIANGLE_WIDTH);
		trianglePolygon << QPoint(x + w + TRIANGLE_HEIGHT, m_top);
		trianglePolygon << QPoint(x + w, m_top + TRIANGLE_WIDTH);
		drawPath.addPolygon(trianglePolygon);
		break;
	}
	painter.drawPath(drawPath);

}

bool CPopupWidget::event(QEvent* e)
{
	if (e->type() == QEvent::WindowDeactivate)
	{
		hide();
		return true;
	}
	return CFramelessWindow::event(e);
}

