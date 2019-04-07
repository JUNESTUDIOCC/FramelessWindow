#ifndef CSideTab_H
#define CSideTab_H
#include "CFramelessWindow.h"

class CSideTab : public CFramelessWindow
{
	Q_OBJECT
public:
	CSideTab(QWidget* parent = 0);
	~CSideTab();

	void SetTop(int top);

protected:
	void paintEvent(QPaintEvent *event);

protected:
	int		m_tabW;
	int		m_tabH;
	int		m_top;
};



#endif