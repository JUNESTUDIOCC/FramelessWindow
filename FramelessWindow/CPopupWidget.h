#ifndef CPopupWidget_H
#define CPopupWidget_H
#include <QWidget>
#include "CFramelessWindow.h"

class CPopupWidgetPrivate;


class CPopupWidget : public CFramelessWindow
{
public:
	CPopupWidget(QWidget* content,QWidget* parent = 0);
	~CPopupWidget();


protected:
	void paintEvent(QPaintEvent *event);

private:
	CPopupWidgetPrivate*	m_d;
};



#endif