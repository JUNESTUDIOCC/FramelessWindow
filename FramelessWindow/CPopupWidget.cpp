#include "CPopupWidget.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QGraphicsDropShadowEffect>


struct CPopupWidgetPrivate
{
	CPopupWidgetPrivate()
	{
	
	}


};

CPopupWidget::CPopupWidget(QWidget* content,QWidget* parent /*= 0*/)
:CFramelessWindow(content,parent),
m_d(new CPopupWidgetPrivate)
{
	//layout()->set
}

CPopupWidget::~CPopupWidget()
{

}

void CPopupWidget::paintEvent(QPaintEvent *event)
{

}
