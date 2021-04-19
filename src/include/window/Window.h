#pragma once
#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>

class WindowUI : public QWidget
{

public:
	WindowUI();
	WindowUI(int, int);
	~WindowUI();

private:
	QProgressBar* _bar;
	QSlider* _slider;
	QPushButton* _btn;
};

#endif // !_WINDOW_H_
