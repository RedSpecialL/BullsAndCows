#include "MainWindow.h"
#include "ui_mainwindow.h"

#include "Utils.h"
#include <QMessageBox>

/**
 * Definitions of the MainWindow class.
 */

// Todo: make config.
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	, m_game(15, bnc::GameStatics::generateNumberTask(4))
{
	ui->setupUi(this);
	setFixedSize(size());
	setConnects();
	setupWidgets();
}

MainWindow::~MainWindow()
{
}

void MainWindow::draw()
{
	ui->tableWidget->clear();
	ui->tableWidget->setHorizontalHeaderLabels(QString("Suggestion;Hint").split(";"));

	int size = m_suggestions.size();
	ui->tableWidget->setRowCount(size);

	QVector<std::string>::const_iterator its = m_suggestions.constBegin();
	QVector<std::string>::const_iterator ith = m_hints.constBegin();

	for (int i = 0; i < size; ++i)
	{
		ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString(its->c_str())));
		ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString(ith->c_str())));
		++its;
		++ith;
	}

	ui->tableWidget->setColumnWidth(0, (ui->tableWidget->width() / 2) - 9);
	ui->tableWidget->setColumnWidth(1, (ui->tableWidget->width() / 2) - 9);
	ui->tableWidget->resizeRowsToContents();

}

void MainWindow::onOkButtonReleased()
{
	try
	{
		std::string suggestion(ui->suggestion->text().toStdString());
		std::string hint(m_game.calculateHint(suggestion));
		m_suggestions.push_back(suggestion);
		m_hints.push_back(hint);

		draw();
	}
	catch(std::runtime_error& e)
	{
		QMessageBox::warning(this, "Error", e.what());
	}
	catch (...)
	{
		QMessageBox::warning(this, "Error", "Unhandled exception.");
	}
}

void MainWindow::setConnects()
{
	connect(ui->okButton, &QPushButton::released, this, &MainWindow::onOkButtonReleased);
}

void MainWindow::setupWidgets()
{
	ui->maxTries->setText("Max tries: 15");
	ui->gameType->setText("Game type: 4 numbers");

	ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
	ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableWidget->setColumnCount(2);
	draw();
}
