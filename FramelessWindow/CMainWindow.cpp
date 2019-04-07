#include <QPainter>
#include "CMainWindow.h"
#include "CPopupWidget.h"
#include "CSideTabWidget.h"
#include "CSideTab.h"
#include <QTabWidget>

#pragma execution_character_set("utf-8")

CMainWindow::CMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_pPop = new CPopupWidget(this);
	m_pPop->resize(300, 500);
	m_pPop->SetBackgroundColor(QColor(0,170,225,200));
	m_pPop->SetTop(80);
	m_pPop->SetDirection(CPopupWidget::AD_RIGHT);

	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(on_btn()));


	CSideTabWidget* pSideWidget = new CSideTabWidget(this);
	QWidget* p = new QPushButton;
	pSideWidget->AddTab(p, "综合显示控制");
	pSideWidget->AddTab(new QTabWidget, "搜狗输入法");
}

void CMainWindow::on_btn()
{
	QPoint pt = this-> mapToGlobal(QPoint(width(),100));
	m_pPop->SetTop(100);
	m_pPop->Resize(350,height());
	m_pPop->Show(pt);
}

void CMainWindow::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	painter.setPen(Qt::black);

	int w, h, x, y, radius;
	radius = 15;

	int m_tabH = 20;
	int m_tabW = 50;
	int m_top = 0;

	w = m_tabH;
	h = m_tabH;
	x = 10;
	y = m_top;

	QPainterPath path;
	path.moveTo(m_tabH, 0);
	path.lineTo(m_tabH-radius, y);
	path.arcTo(0, 0, radius, radius, 90.0f, 90.0f);
	path.lineTo(0, m_tabW - radius);
	/*path.arcTo(x, y + m_tabW - radius, radius * 2, radius * 2, 90.0f, 90.0f);
	path.lineTo(x + m_tabH, m_top - m_tabW);*/

	painter.drawPath(path);
}
