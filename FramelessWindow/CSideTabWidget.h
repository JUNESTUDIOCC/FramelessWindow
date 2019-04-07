#ifndef CSideTabWidget_H
#define CSideTabWidget_H
#include <QWidget>
#include <QStackedWidget>
#include <map>

using namespace std;

class QPushButton;
class CPopupWidget;

class CSideTabWidget : public QWidget
{
	Q_OBJECT
public:
	CSideTabWidget(QWidget* parent);

	~CSideTabWidget();

	void AddTab(QWidget* page,const QString& tabName);

	void Clear();

	int GetCount();

	int IndexOf(QWidget* w);

	QWidget* GetWidget(int index);

	QString TabText(int index);

protected slots:
	void slot_showPopup();

protected:
	bool eventFilter(QObject *watched, QEvent *event);

	void resizeEvent(QResizeEvent *event);

protected:
	QWidget*						m_parent;
	map<int, QPushButton*>			m_tabs;
	CPopupWidget*					m_popup;
	QStackedWidget*					m_stackedWidget;
};




#endif