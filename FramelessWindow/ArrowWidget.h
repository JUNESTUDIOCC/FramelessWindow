#pragma once
#include <QWidget>

class ArrowWidget : public QWidget
{
	Q_OBJECT

public:
	ArrowWidget(QWidget *parent = 0);

	// 设置小三角起始位置;
	void setStartPos(int startX);

	// 设置小三角宽和高;
	void setTriangleInfo(int width, int height);

	// 设置中间区域widget;
	void setCenterWidget(QWidget* widget);

protected:
	void paintEvent(QPaintEvent *);

private:
	// 小三角起始位置;
	int m_startX;
	// 小三角的宽度;
	int m_triangleWidth;
	// 小三角高度;
	int m_triangleHeight;
};
