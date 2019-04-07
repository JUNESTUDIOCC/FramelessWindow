#include "CMainWindow.h"
#include <QtWidgets/QApplication>
#include "CFramelessWindow.h"
#include "ArrowWidget.h"
#include "CPopupWidget.h"
#include "CSideTab.h"
#include <QPushButton>
#include <QLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWidget* w = new QWidget();
	CPopupWidget w1(0);
	w1.resize(500, 500);
	w1.setWindowOpacity(0.5);
	w1.layout()->addWidget(new QPushButton(&w1));
	w1.SetBackgroundColor(QColor(225,225,122));
	//w1.Show(500, 500);

	CMainWindow x;
	x.show();


	QLabel* textLabel = new QLabel;
	textLabel->setAlignment(Qt::AlignCenter);
	textLabel->setText("ArrowWidget");

	ArrowWidget w2;
	w2.setStartPos(60);
	w2.setTriangleInfo(20, 12);
	w2.setFixedSize(QSize(150, 80));
	//w2.setCenterWidget(textLabel);
	//w2.show();

	//CSideTab* p = new CSideTab(0);
	//p->showMaximized();


	return a.exec();
}
