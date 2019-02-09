#include "CMainWindow.h"
#include <QtWidgets/QApplication>
#include "CFramelessWindow.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWidget* w = new QWidget();
	CFramelessWindow w1(w);
	w1.setGeometry(0, 0, 500, 500);

	w1.show();

	return a.exec();
}
