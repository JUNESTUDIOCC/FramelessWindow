#include "CSideTabWidget.h"
#include "CPopupWidget.h"
#include <QPushButton>
#include <QVBoxLayout>

CSideTabWidget::CSideTabWidget(QWidget* parent)
:QWidget(parent)
{
	parent->installEventFilter(this);

	m_popup = new CPopupWidget(this);
	m_popup->setWindowOpacity(0.8);
	m_stackedWidget = new QStackedWidget(m_popup);
	m_popup->SetCentralWidget(m_stackedWidget);
}

CSideTabWidget::~CSideTabWidget()
{

}

void CSideTabWidget::AddTab(QWidget* page, const QString& tabName)
{
	int index = m_stackedWidget->addWidget(page);
	QPushButton* pTab = new QPushButton(tabName.split("", QString::SkipEmptyParts).join("\n"), this);
	pTab->setFixedSize(30, 120);
	connect(pTab, SIGNAL(clicked(bool)), this, SLOT(slot_showPopup()));
	m_tabs[index] = pTab;
}

void CSideTabWidget::Clear()
{
	map<int, QPushButton*>::iterator itr = m_tabs.begin();
	while (itr != m_tabs.end())
	{
		QPushButton*& pTab = itr->second;
		pTab->deleteLater();
		++itr;
	}
	m_tabs.clear();

	for (int i = 0; i < m_stackedWidget->count(); i++)
	{
		QWidget* w = m_stackedWidget->widget(i);
		m_stackedWidget->removeWidget(w);
		w->deleteLater();
	}
}

int CSideTabWidget::GetCount()
{
	return m_stackedWidget->count();
}

int CSideTabWidget::IndexOf(QWidget* w)
{
	return m_stackedWidget->indexOf(m_stackedWidget);
}

QWidget* CSideTabWidget::GetWidget(int index)
{
	return m_stackedWidget->widget(index);
}

QString CSideTabWidget::TabText(int index)
{
	map<int, QPushButton*>::iterator itr = m_tabs.find(index);
	if (itr != m_tabs.end())
	{
		return itr->second->text().replace("\n", "");
	}
	return QString();
}

void CSideTabWidget::slot_showPopup()
{
	QPushButton* pBnt = qobject_cast<QPushButton*>(sender());
	if (pBnt)
	{
		map<int, QPushButton*>::iterator itr = m_tabs.begin();
		while (itr != m_tabs.end())
		{
			QPushButton*& pTab = itr->second;
			if (pBnt == pTab)
			{
				int index = itr->first;
				m_stackedWidget->setCurrentIndex(index);
				break;
			}
			++itr;
		}

		int top = pBnt->pos().y() + 0.5*pBnt->height();
		m_popup->SetTop(top);
		QPoint pt = mapToGlobal(QPoint(pBnt->pos().x(), top));
		m_popup->Show(pt);
	}
}

bool CSideTabWidget::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == parent())
	{
		QWidget* parentWidget = static_cast<QWidget*>(watched);
		resize(parentWidget->size());
	}
	return false;
}

void CSideTabWidget::resizeEvent(QResizeEvent *event)
{
	m_popup->Resize(500, height());

	map<int, QPushButton*>::iterator itr = m_tabs.begin();
	QPushButton* prevTab = 0;;
	while (itr != m_tabs.end())
	{
		QPushButton*& pTab = itr->second;
		if (prevTab)
		{
			pTab->move(width() - pTab->width(), prevTab->height());
		}
		else
		{
			pTab->move(width() - pTab->width(), 0);
		}
		prevTab = pTab;
		++itr;
	}
}

