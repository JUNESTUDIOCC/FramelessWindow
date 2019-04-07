#include "CSideTab.h"
#include <QPainter>

CSideTab::CSideTab(QWidget* parent /*= 0*/)
:CFramelessWindow(parent),
m_tabW(40),
m_tabH(80),
m_top(20)

{

}

CSideTab::~CSideTab()
{

}

void CSideTab::SetTop(int top)
{
	m_top = top;
}

void CSideTab::paintEvent(QPaintEvent *event)
{
	CFramelessWindow::paintEvent(event);
	return;

	QPainterPath drawPath;
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing, true);
	painter.setPen(Qt::NoPen);
	painter.setBrush(GetBackgroundColor());

	int w, h, x, y, radius;
	radius = GetWidgetRadius();

	w = m_tabH;
	h = m_tabH;
	x = GetBlurRadius();
	y = m_top;

	QPainterPath path;
	path.moveTo(x + m_tabH, m_top);
	path.lineTo(x+radius, m_top);
	path.arcTo(x, m_top, radius, radius, 90.0f, 90.0f);
	path.lineTo(x, y+m_tabW-radius);
	path.arcTo(x+radius, y + m_tabW - radius, radius, radius, 90.0f, 90.0f);
	path.lineTo(x + m_tabH, m_top+m_tabW);

	painter.drawPath(path);
}

