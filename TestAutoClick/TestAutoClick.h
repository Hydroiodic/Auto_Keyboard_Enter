#pragma once

#include "ui_TestAutoClick.h"
#include <QtWidgets/QMainWindow>
#include <thread>
#include <Windows.h>

class TestAutoClick : public QMainWindow
{
	Q_OBJECT

public:
	TestAutoClick(QWidget* parent = nullptr);
	~TestAutoClick();

private:
	Ui::TestAutoClickClass ui;

private:
	bool run_click = false;
	std::thread* current_thread = nullptr;

	void click_looping() const;

private slots:
	void on_button_clicked();
};
