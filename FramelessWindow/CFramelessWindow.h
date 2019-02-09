#ifndef CFramelessWindow_H
#define CFramelessWindow_H
#include <QWidget>


class CFramelessWindowPrivate;

enum PosType
{
	PT_CONTENT,
	PT_LEFT,
	PT_TOP,
	PT_RIGHT,
	PT_BOTTOM,
	PT_LEFT_TOP,
	PT_TOP_RIGHT,
	PT_RIGHT_BOTTOM,
	PT_BOTTOM_LEFT
};

class CFramelessWindow : public QWidget
{
	Q_OBJECT
public:
	CFramelessWindow(QWidget* contentWidget,QWidget* parent = 0);
	~CFramelessWindow();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	bool eventFilter(QObject *watched, QEvent *event);
private:
	PosType GetPosType(const QPoint& pt);

private:
	CFramelessWindowPrivate* m_d;
};


#endif