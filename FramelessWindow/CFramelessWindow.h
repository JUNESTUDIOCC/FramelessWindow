#ifndef CFramelessWindow_H
#define CFramelessWindow_H
#include <QWidget>


class CFramelessWindowPrivate;

class CFramelessWindow : public QWidget
{
	Q_OBJECT
public:
	CFramelessWindow(QWidget* parent = 0);

	~CFramelessWindow();

	int GetBlurRadius();

	int GetWidgetRadius();

	const QColor& GetShadowColor();

	const QColor& GetBackgroundColor();

	bool GetDragEnabled();

	bool GetResizeEnabled();

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

	void paintEvent(QPaintEvent *event);

private:
	int		GetPosType(const QPoint& pt);

private:
	CFramelessWindowPrivate* m_d;
};


#endif