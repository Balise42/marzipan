
#include <QtWidgets/QAction>
#include "RasterWindow.h"
#include <QMenuBar>

void RasterWindow::createActions() {
    undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    connect(undoAct, &QAction::triggered, this, &RasterWindow::undo);

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    connect(redoAct, &QAction::triggered, this, &RasterWindow::redo);

    saveImageAct = new QAction(tr("Save Image"), this);
    connect(saveImageAct, &QAction::triggered, this, &RasterWindow::saveImage);

    saveParamsAct = new QAction(tr("&Save Params"), this);
    saveParamsAct->setShortcuts(QKeySequence::Save);
    connect(saveParamsAct, &QAction::triggered, this, &RasterWindow::saveParams);

    loadParamsAct = new QAction(tr("&Open Params"), this);
    loadParamsAct->setShortcuts(QKeySequence::Open);
    connect(loadParamsAct, &QAction::triggered, this, &RasterWindow::loadParams);
}

RasterWindow::RasterWindow() {
    setGeometry(100, 100, 900, 600);
    setCentralWidget(widget);
    createActions();
}

#ifndef QT_NO_CONTEXTMENU

void RasterWindow::contextMenuEvent(QContextMenuEvent *event) {
    QMenu menu(this);
    menu.addAction(saveImageAct);
    menu.addAction(saveParamsAct);
    menu.addAction(loadParamsAct);
    menu.addAction(undoAct);
    menu.addAction(redoAct);
    menu.exec(event->globalPos());
}

#endif // QT_NO_CONTEXTMENU

void RasterWindow::undo() {
    widget->undo();
}

void RasterWindow::redo() {
    widget->redo();
}

void RasterWindow::saveImage() {
    widget->saveImage();
}

void RasterWindow::saveParams() {
    widget->saveParams();
}

void RasterWindow::keyReleaseEvent(QKeyEvent *event) {
    widget->processKeyEvent(event->key());
}

void RasterWindow::loadParams() {
    widget->loadParams();
}