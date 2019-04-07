#include <QPainter>
#include "CMainWindow.h"
#include "CPopupWidget.h"

CMainWindow::CMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_pPop = new CPopupWidget(this);
	m_pPop->resize(300, 500);
	m_pPop->SetBackgroundColor(QColor(0,170,225,200));
	m_pPop->SetTop(80);
	m_pPop->SetArrowDirection(CPopupWidget::AD_RIGHT);

	
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(on_btn()));
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

	painter.drawLine(QPoint(0, 0), QPoint(100, 100));
}
