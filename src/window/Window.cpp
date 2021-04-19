#include "../../src/include/window/Window.h"

WindowUI::WindowUI() : QWidget()
{
	setFixedSize(1080, 1024);
	_bar = new QProgressBar(this);
	_bar->setGeometry(10, 60, 150, 20);
	_bar->move(50, 20);

	_slider = new QSlider(Qt::Horizontal, this);
	_slider->setGeometry(10, 60, 150, 20);
	QObject::connect(_slider, SIGNAL(valueChanged(int)), _bar, SLOT(setValue(int)));

	_btn = new QPushButton("reset", this);
	_btn->move(50, 20);
	QObject::connect(_btn, SIGNAL(pressed()), _bar, SLOT(reset()));
	QObject::connect(_btn, SIGNAL(pressed()), _slider, SLOT(resetSlider()));
}

WindowUI::WindowUI(int width, int height) : QWidget()
{
	setFixedSize(width, height);
	_bar = new QProgressBar(this);
	_bar->setGeometry(10, 60, 150, 20);
	_bar->move(50, 20);

	_slider = new QSlider(Qt::Horizontal, this);
	_slider->setGeometry(10, 60, 150, 20);
	QObject::connect(_slider, SIGNAL(valueChanged(int)), _bar, SLOT(setValue(int)));

	_btn = new QPushButton("reset", this);
	_btn->move(50, 40);
	QObject::connect(_btn, SIGNAL(clicked()), _bar, SLOT(reset()));
	QObject::connect(_btn, SIGNAL(pressed()), _slider, SLOT(resetSlider()));
}

WindowUI::~WindowUI()
{
	delete _bar;
	delete _slider;
	delete _btn;
}