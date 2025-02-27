#include "ArrowWidget.h"

#include "ArrowWidget.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QGraphicsDropShadowEffect>

#define SHADOW_WIDTH 15                 // 窗口阴影宽度;
#define TRIANGLE_WIDTH 15               // 小三角的宽度;
#define TRIANGLE_HEIGHT 10              // 小三角的高度;
#define BORDER_RADIUS 5                 // 窗口边角的弧度;

ArrowWidget::ArrowWidget(QWidget *parent)
: QWidget(parent)
, m_startX(50)
, m_triangleWidth(TRIANGLE_WIDTH)
, m_triangleHeight(TRIANGLE_HEIGHT)
{
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);

	// 设置阴影边框;
	auto shadowEffect = new QGraphicsDropShadowEffect(this);
	shadowEffect->setOffset(0, 0);
	shadowEffect->setColor(Qt::gray);
	shadowEffect->setBlurRadius(SHADOW_WIDTH);
	this->setGraphicsEffect(shadowEffect);

	setFixedSize(150, 200);
}

void ArrowWidget::setCenterWidget(QWidget* widget)
{
	QHBoxLayout* hMainLayout = new QHBoxLayout(this);
	hMainLayout->addWidget(widget);
	hMainLayout->setSpacing(0);
	hMainLayout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH + TRIANGLE_HEIGHT, SHADOW_WIDTH, SHADOW_WIDTH);
}

// 设置小三角显示的起始位置;
void ArrowWidget::setStartPos(int startX)
{
	m_startX = startX;
}

void ArrowWidget::setTriangleInfo(int width, int height)
{
	m_triangleWidth = width;
	m_triangleHeight = height;
}

void ArrowWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(Qt::NoPen);
	painter.setBrush(QColor(255, 255, 255));

	// 小三角区域;
	QPolygon trianglePolygon;
	trianglePolygon << QPoint(m_startX, m_triangleHeight + SHADOW_WIDTH);
	trianglePolygon << QPoint(m_startX + m_triangleWidth / 2, SHADOW_WIDTH);
	trianglePolygon << QPoint(m_startX + m_triangleWidth, m_triangleHeight + SHADOW_WIDTH);

	QPainterPath drawPath;
	drawPath.addRoundedRect(QRect(SHADOW_WIDTH, m_triangleHeight + SHADOW_WIDTH, \
		width() - SHADOW_WIDTH * 2, height() - SHADOW_WIDTH * 2 - m_triangleHeight), \
		BORDER_RADIUS, BORDER_RADIUS);
	// Rect + Triangle;
	drawPath.addPolygon(trianglePolygon);
	painter.drawPath(drawPath);
}
