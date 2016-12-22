#pragma once
#include <qmainwindow.h>


namespace Ui {
	class MainWindow;
}

//////////////////////////////////////////////////////////////////////////
// Interface of the MainWindow class.
//

class MainWindow : public QMainWindow
{
	Q_OBJECT

		//
		// Construction and destruction.
		//
public:
	//! Constructor.
	explicit MainWindow(QWidget *parent = 0);
	//! Destructor.
	~MainWindow() = default;

	//
	// Private data members.
	//
private:
	//! Pointer to the class object.
	Ui::MainWindow *ui;
};
