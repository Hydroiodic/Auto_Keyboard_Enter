#include "TestAutoClick.h"

TestAutoClick::TestAutoClick(QWidget* parent) : QMainWindow(parent) {
	ui.setupUi(this);
}

TestAutoClick::~TestAutoClick() {
	// release thread and memory resources
	if (current_thread) {
		this->run_click = false;
		current_thread->join();
		delete current_thread;
	}
}

void TestAutoClick::click_looping() const {
	while (this->run_click) {
		// enter space automatically
		keybd_event(VK_SPACE, 0, 0, 0);
		// sleep for a while
		Sleep(500);
	}
}

void TestAutoClick::on_button_clicked() {
	this->run_click = !this->run_click;
	if (this->run_click) {
		// start a new thread to run space entering
		assert(!this->current_thread);
		current_thread = new std::thread(&TestAutoClick::click_looping, this);

		// set text for the button
		this->ui.clickButton->setText(tr("Stop"));
	}
	else {
		// join the previously created thread
		assert(this->current_thread);
		current_thread->join();
		delete current_thread;
		current_thread = nullptr;

		// set text for the button
		this->ui.clickButton->setText(tr("Start"));
	}
}
