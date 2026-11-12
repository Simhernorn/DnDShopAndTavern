#include <QApplication>
#include "tavernWindow.h"

int main(int argc, char * argv[]) {
	QApplication app(argc,argv);
	ProductWindow window;
	window.show();
	return app.exec();
}
