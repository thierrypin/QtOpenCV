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

    /*
     * Lado esquerdo da tela
     */
    vbox_left = make_shared<QVBoxLayout>();

    // Label dados usuario
    vbox_left->addWidget(lbl_dados_usuario.get());

    // HBox nome
    hbox_vbox_left_1 = make_shared<QVBoxLayout>();
    hbox_vbox_left_1->addWidget(lbl_nome.get());
    hbox_vbox_left_1->addWidget(nome.get());

    vbox_left->addLayout(hbox_vbox_left_1.get());

    // HBox matricula
    hbox_vbox_left_2 = make_shared<QVBoxLayout>();
    hbox_vbox_left_2->addWidget(lbl_matricula.get());
    hbox_vbox_left_2->addWidget(matricula.get());

    vbox_left->addLayout(hbox_vbox_left_2.get());

    // HBox rostos
    hbox_vbox_left_3 = make_shared<QVBoxLayout>();
    hbox_vbox_left_3->addWidget(img_face.get());
    //hbox_vbox_left_3->addWidget(PLACEHOLDER.get());

    vbox_left->addLayout(hbox_vbox_left_3.get());

    // Status acesso
    vbox_left->addLayout(status_acesso.get());

    // Data
    vbox_left->addLayout(data.get());

    /*
     * Lado direito da tela
     */
    vbox_right = make_shared<QVBoxLayout>();

    // Label posicionamento
    vbox_right->addWidget(lbl_posicionamento.get());

    // Imagem da camera
    vbox_left->addWidget(img.get());

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


