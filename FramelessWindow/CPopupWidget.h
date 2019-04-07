#ifndef CPopupWidget_H
#define CPopupWidget_H
#include <QWidget>
#include "CFramelessWindow.h"


class CPopupWidget : public CFramelessWindow
{
public:
	enum ArrowDirection
	{
		AD_UP,
		AD_DOWN,
		AD_LEFT,
		AD_RIGHT
	};
public:
	CPopupWidget(QWidget* parent = 0);

	~CPopupWidget();

	void SetArrowDirection(ArrowDirection arrowDirction);

	void Show(int x, int y);

	void Show(const QPoint& pt);

	void SetTop(int top);

	void Resize(int w,int h);

protected:
	void paintEvent(QPaintEvent *event);
	bool event(QEvent* e);

private:
	ArrowDirection			m_arrowDirction;
	int						m_top;
};



#endif