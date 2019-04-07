#include "CMainWindow.h"
#include <QtWidgets/QApplication>
#include "CFramelessWindow.h"
#include "ArrowWidget.h"
#include "CPopupWidget.h"
#include <QLabel>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWidget* w = new QWidget();
	CFramelessWindow w1(0);
	w1.move(200, 200);
	w1.resize(500, 500);

	w1.SetBackgroundColor(QColor(225,225,122,150));

	//w1.show();

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




	return a.exec();
}
