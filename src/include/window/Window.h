#pragma once
#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>
#include <QFileDialog>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QMenu>

class WindowUI : public QWidget
{
	Q_OBJECT
	enum class State {
		Save = 0,
		Export = 1,
	};

public:
	WindowUI();
	WindowUI(int, int);
	~WindowUI();
	void init();
	QString openFolder();
	QString openFile();
	bool makeSave(State);

private:
	QProgressBar* _bar;
	QSlider* _slider;
	QPushButton* _btn;
	QPushButton* _close;
	QMenu* _menu;
};

#endif // !_WINDOW_H_
