#include "stdafx.h"
#include "Groups.h"

Groups::Groups(QWidget *parent)
	: QMainWindow(parent),
      screenHeight(0),
      screenWidth(0),
      windowHeight(0),
      windowWidth(0)
{
	ui.setupUi(this);
    
}

//Extend show method of base class
void Groups::show()
{
    centerAndResize();
    setBackgroundColor(255,255,255);

    OutputDebugStringA("Here");

    //run show of base class
    QMainWindow::show();
}



// get the dimension available on this screen
void Groups::centerAndResize()
{
    QSize availableSize = qApp->desktop()->availableGeometry().size();

    screenWidth = availableSize.width();
    screenHeight = availableSize.height();

    //Control how large window is relative to screen dimensions
    windowWidth = screenWidth * 0.75;
    windowHeight = screenHeight * 0.75;

    QSize newSize(windowWidth, windowHeight);

    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            newSize,
            qApp->desktop()->availableGeometry()
        )
    );
}

void Groups::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 4, Qt::SolidLine, Qt::FlatCap));
    painter.drawLine(windowWidth*.4,windowHeight*.111, windowWidth* .4, windowHeight*.889);


}

void Groups::resizeEvent(QResizeEvent* event)
{
    //Reset window size
    QSize availableSize = qApp->desktop()->availableGeometry().size();

    windowWidth = size().width();
    windowHeight = size().height();

    //Update widget
    update();
}

void Groups::setBackgroundColor(int r, int g, int b)
{
    QPalette pal = palette();

    // set black background
    pal.setColor(QPalette::Background, QColor(r,g,b));
    setAutoFillBackground(true);
    setPalette(pal);

}
