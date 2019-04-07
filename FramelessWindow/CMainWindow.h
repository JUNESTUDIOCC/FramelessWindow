#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CMainWindow.h"

class CPopupWidget;
class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = Q_NULLPTR);


protected slots:
void on_btn();

protected:
	void paintEvent(QPaintEvent *event);

private:
	Ui::CMainWindowClass ui;
	CPopupWidget*	m_pPop;
};
