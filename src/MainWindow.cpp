//
// Created by thierry on 23/09/2020.
//

#include <iostream>
#include "MainWindow.hpp"

using namespace std;
using namespace cv;

MainWindow::MainWindow()
{
    cap.open(0);

//    this->



    this->draw();
    this->show();
}

void MainWindow::draw()
{
    // Criação dos componentes da interface
    window = make_shared<QWidget>();
    layout = make_shared<QHBoxLayout>();


    // Ligação dos elementos ao layout
//    layout->addWidget(button1.get());

    window->setLayout(layout.get());

    this->setCentralWidget(window.get());
}

void MainWindow::refresh()
{
    Mat frame;
    bool ret = cap.read(frame);

    if (!ret)
    {
        cerr << "Câmera falhou" << endl;
        exit(1);
    }

    frame_container = make_shared<QImage>((const unsigned char*) (frame.data), frame.cols, frame.rows, QImage::Format_RGB888);

    QImage& tmp = *frame_container;
    this->img->setPixmap(QPixmap::fromImage(tmp));
    this->img->resize(this->img->pixmap()->size());
}


