#include "../../src/include/window/Window.h"
#include <iostream>
#include <QScreen>

WindowUI::WindowUI() : QWidget()
{
	setFixedSize(1080, 1024);
}

WindowUI::WindowUI(int width, int height) : QWidget()
{
	setFixedSize(width, height);
}

WindowUI::~WindowUI()
{
	delete _bar;
	delete _slider;
	delete _btn;
	delete _close;
}

void WindowUI::init()
{
	_bar = new QProgressBar(this);
	_bar->setGeometry(10, 60, 150, 20);
	_bar->move(50, 20);

	_slider = new QSlider(Qt::Horizontal, this);
	_slider->setGeometry(10, 60, 150, 20);
	QObject::connect(_slider, SIGNAL(valueChanged(int)), _bar, SLOT(setValue(int)));

	_btn = new QPushButton("reset", this);
	_btn->move(50, 40);
	QObject::connect(_btn, SIGNAL(clicked()), _bar, SLOT(reset()));
	_close = new QPushButton("Close", this);
	_close->move(200, 40);
	QObject::connect(_close, SIGNAL(clicked()), qApp, SLOT(quit()));
}

QString WindowUI::openFolder()
{
	return QFileDialog::getExistingDirectory(this);
}

QString WindowUI::openFile()
{
	return QFileDialog::getOpenFileName(this, "Select a file");
}

bool WindowUI::makeSave(WindowUI::State value)
{
	QString filename = value == State::Export ?
		QFileDialog::getSaveFileName(this, tr("Export"), QString(), tr("Text files (*.txt);; XML files (*.xml)")) :
		QFileDialog::getSaveFileName(this, tr("Save as"), QString(), tr("Text files (*.txt)"));

	if (filename.isEmpty())
		return false;

	QFile file(filename);
	if (!file.open(QIODevice::ReadWrite))
		return false;
	if (file.open(QIODevice::ReadWrite)) {
		QTextStream output(&file);
		output << "creation of file test";
	}
	file.close();
	return true;
}