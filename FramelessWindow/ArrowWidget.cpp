#include "ArrowWidget.h"

#include "ArrowWidget.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QGraphicsDropShadowEffect>

#define SHADOW_WIDTH 15                 // ������Ӱ���;
#define TRIANGLE_WIDTH 15               // С���ǵĿ��;
#define TRIANGLE_HEIGHT 10              // С���ǵĸ߶�;
#define BORDER_RADIUS 5                 // ���ڱ߽ǵĻ���;

ArrowWidget::ArrowWidget(QWidget *parent)
: QWidget(parent)
, m_startX(50)
, m_triangleWidth(TRIANGLE_WIDTH)
, m_triangleHeight(TRIANGLE_HEIGHT)
{
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);

	// ������Ӱ�߿�;
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

// ����С������ʾ����ʼλ��;
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

	// С��������;
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
