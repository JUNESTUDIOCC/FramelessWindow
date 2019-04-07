#ifndef CArrowPushButton_H
#define CArrowPushButton_H

#include <QPushButton>

class QLabel;

class CArrowPushButton : public QPushButton
{
	Q_OBJECT
public:
	enum ArrowDirction
	{
		AD_LEFT,
		AD_RIGHT
	};

public:
	CArrowPushButton(QWidget *parent = 0);
	CArrowPushButton(const QString& text, QWidget *parent = 0);
	~CArrowPushButton();

	ArrowDirction GetArrowDirction();
	QString GetText();

	void SetText(const QString& text);
	void SetArrowDirction(ArrowDirction dirct);

signals:
	void signal_pull();
	void signal_push();
protected slots:
	void slot_clicked();
private:
	void init();
protected:
	ArrowDirction	m_dirct;
	QLabel*			m_arrowLabel;
	QLabel*			m_textLabel;
};


#endif