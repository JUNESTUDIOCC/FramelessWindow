#include "CArrowPushButton.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QFontMetrics>
#include <QSizePolicy>

CArrowPushButton::CArrowPushButton(const QString& text,QWidget *parent)
	: QPushButton(parent),
	m_arrowLabel(0),
	m_textLabel(0),
	m_dirct(AD_LEFT)
{
	init();
	SetText(text);
	SetArrowDirction(m_dirct);
}

CArrowPushButton::CArrowPushButton(QWidget *parent /*= 0*/)
: QPushButton(parent),
	m_arrowLabel(0),
	m_textLabel(0),
	m_dirct(AD_LEFT)
{
	init();
	SetArrowDirction(m_dirct);
}

CArrowPushButton::~CArrowPushButton()
{
}

CArrowPushButton::ArrowDirction CArrowPushButton::GetArrowDirction()
{
	return m_dirct;
}

QString CArrowPushButton::GetText()
{
	return m_textLabel->text().replace("\n","");
}

void CArrowPushButton::SetText(const QString& text)
{
	m_textLabel->setText(text.split("", QString::SkipEmptyParts).join("\n"));
	m_textLabel->adjustSize();
}

void CArrowPushButton::SetArrowDirction(ArrowDirction dirct)
{
	m_dirct = dirct;
	switch (m_dirct)
	{
	case CArrowPushButton::AD_LEFT:
		m_arrowLabel->setText("<");
		break;
	case CArrowPushButton::AD_RIGHT:
		m_arrowLabel->setText(">");
		break;
	default:
		break;
	}
}

void CArrowPushButton::slot_clicked()
{
	switch (m_dirct)
	{
	case CArrowPushButton::AD_LEFT:
		SetArrowDirction(AD_RIGHT);
		emit signal_pull();
		break;
	case CArrowPushButton::AD_RIGHT:
		SetArrowDirction(AD_LEFT);
		emit signal_push();
		break;
	default:
		break;
	}
}

void CArrowPushButton::init()
{
	m_arrowLabel = new QLabel(this);
	m_textLabel = new QLabel(this);

	QHBoxLayout* pLayout = new QHBoxLayout();
	pLayout->setSpacing(0);
	pLayout->setContentsMargins(3, 3, 3, 3);
	pLayout->addWidget(m_arrowLabel);
	pLayout->addWidget(m_textLabel);
	this->setLayout(pLayout);
}
