#pragma once

#include "stdafx.h"
#include "ui_Groups.h"

class Groups : public QMainWindow
{
	Q_OBJECT

private:
	Ui::GroupsClass ui;
	void centerAndResize();
	void paintEvent(QPaintEvent* event);
	void resizeEvent(QResizeEvent* event);
	void setBackgroundColor(int r, int g, int b);

	int screenWidth, screenHeight;
	int windowWidth, windowHeight;


public:
	Groups(QWidget *parent = Q_NULLPTR);

	void show();



};
