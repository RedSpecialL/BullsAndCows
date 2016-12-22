#pragma once

#include <QMainWindow>
#include <QVector>
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
	 * Signals.
	 */
signals:
	void gameStatusCheck();

	/**
	 * Private slots.
	 */
private slots:
	/** Checks game status.*/
	void onGameStatusCheck();
	/** Starts new game.*/
	void onNewGameTriggered();
	/** Reads player suggestion.*/
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
	/** Container adapter for hints.*/
	QVector<std::string> m_hints;
	/** Container adapter for player suggestions*/
	QVector<std::string> m_suggestions;
};
