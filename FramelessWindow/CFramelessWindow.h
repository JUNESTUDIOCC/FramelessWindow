#ifndef CFramelessWindow_H
#define CFramelessWindow_H
#include <QWidget>


class CFramelessWindowPrivate;

class CFramelessWindow : public QWidget
{
	Q_OBJECT
public:
	CFramelessWindow(QWidget* contentWidget,QWidget* parent = 0);
	~CFramelessWindow();

	void SetBlurRadius(int radius);
	void SetWidgetRadius(int radius);
	void SetShadowColor(const QColor &color);
	void SetBackgroundColor(const QColor &color);
	void SetDragEnabled(bool dragEnabled);
	void SetResizeEnabled(bool resizeEnabled);

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	bool eventFilter(QObject *watched, QEvent *event);
private:
	int		GetPosType(const QPoint& pt);
	void    Update();

private:
	CFramelessWindowPrivate* m_d;
};


#endif