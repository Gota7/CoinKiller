#ifndef SPRITESEDITOR_H
#define SPRITESEDITOR_H

#include "spritedata.h"
#include "level.h"

#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QTreeWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QGridLayout>

class SpriteValueFieldWidget : public QSpinBox
{
    Q_OBJECT
public:
    SpriteValueFieldWidget(Sprite* sprite, Field* field);
    void updateValue();
private slots:
    void handleValueChange(int value);
signals:
    void updateHex();
private:
    Sprite* sprite;
    Field* field;
    bool handleValueChanges;
};

class SpriteCheckboxFieldWidget : public QCheckBox
{
    Q_OBJECT
public:
    SpriteCheckboxFieldWidget(Sprite* sprite, Field* field);
    void updateValue();
private slots:
    void handleValueChange(bool checked);
signals:
    void updateHex();
private:
    Sprite* sprite;
    Field* field;
    bool handleValueChanges;
};

class SpriteListFieldWidget : public QComboBox
{
    Q_OBJECT
public:
    SpriteListFieldWidget(Sprite* sprite, Field* field);
    void updateValue();
private slots:
    void handleIndexChange(QString text);
signals:
    void updateHex();
private:
    Sprite* sprite;
    Field* field;
    bool handleValueChanges;
};

class SpriteDataEditorWidget : public QWidget
{
    Q_OBJECT
public:
    SpriteDataEditorWidget(SpriteData* spriteData);
    void select(Sprite* sprite);
    void deselect();
    void updateEditor() {}

private slots:
    void handleRawSpriteDataChange(QString text);
    void updateRawSpriteData();

signals:
    void updateLevelView();

private:
    QGridLayout* layout;
    QLineEdit* rawSpriteData;

    SpriteData* spriteData;
    Sprite* editSprite;
    bool editingASprite = false;

    QLabel* spriteName;
    QList<QLabel*> fieldNames;
    QList<SpriteValueFieldWidget*> valueFieldWidgets;
    QList<SpriteListFieldWidget*> listFieldWidgets;
    QList<SpriteCheckboxFieldWidget*> checkboxFieldWidgets;

    void addField(Field* field, int pos);
};

class SpriteEditorWidget : public QWidget
{
    Q_OBJECT
public:
    SpriteEditorWidget();
    void select(Sprite* sprite);
    SpriteDataEditorWidget* spriteDataEditorPtr() { return editor; }

signals:
    void selectedSpriteChanged(int);

public slots:
    void setView(int view);
    void search(QString text);

private slots:
    void handleIndexChange(QTreeWidgetItem *item);

private:
    SpriteData spriteData;
    QComboBox* viewComboBox;
    QLineEdit* searchEdit;
    QTreeWidget* spriteTree;

    SpriteDataEditorWidget* editor;
};

#endif // SPRITESEDITOR_H
