#pragma once
#include <QWidget>

class ArrowWidget : public QWidget
{
	Q_OBJECT

public:
	ArrowWidget(QWidget *parent = 0);

	// ����С������ʼλ��;
	void setStartPos(int startX);

	// ����С���ǿ�͸�;
	void setTriangleInfo(int width, int height);

	// �����м�����widget;
	void setCenterWidget(QWidget* widget);

protected:
	void paintEvent(QPaintEvent *);

private:
	// С������ʼλ��;
	int m_startX;
	// С���ǵĿ��;
	int m_triangleWidth;
	// С���Ǹ߶�;
	int m_triangleHeight;
};
