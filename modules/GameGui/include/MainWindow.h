#pragma once

#include <QMainWindow>
#include <QMap>
#include "Rules.h"
#include <string>

namespace Ui {
	class MainWindow;
}

/**
 * Interface of the MainWindow class.
 */

class MainWindow : public QMainWindow
{
	Q_OBJECT

	/**
	 * Construction and destruction.
	 */
public:
	/** Constructor.*/
	explicit MainWindow(QWidget *parent = 0);
	/** Destructor.*/
	~MainWindow();

	/**
	 * Private slots.
	 */
private slots:
	/**  */
	void onOkButtonReleased();

	/**
	 * Private methods.
	 */
private:
	/** Draws turn history.*/
	void draw();
	/** Sets Qt connects.*/
	void setConnects();
	/** Sets widgets parameters.*/
	void setupWidgets();

	/**
	 * Private data members.
	 */
private:
	/** Contains current rules.*/
	bnc::GameRules m_game;
	/** Pointer to the ui object.*/
	Ui::MainWindow *ui;
	/** Container adapter to all player suggestions and hints.*/
	QMap<std::string, std::string> m_suggestionHints;
};
