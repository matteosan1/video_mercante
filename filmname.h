#ifndef FILMNAME_H
#define FILMNAME_H

#include <QObject>
#include <QVariantList>

class FilmName : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString fileSource READ fileSource WRITE setFileSource NOTIFY fileSourceChanged)
    Q_PROPERTY(QString domanda READ domanda WRITE setDomanda NOTIFY domandaChanged)
    Q_PROPERTY(QString titolo READ titolo WRITE setTitolo NOTIFY titoloChanged)

public:
    explicit FilmName(const QString& filename, QObject *parent = 0);

    void setFileSource(const QString& aFile) {}
    QString fileSource() const { return m_fileSources[m_film]; }
    void setDomanda(const QString& aDomanda) {}
    QString domanda() const { return m_domande[m_film]; }
    void setTitolo(const QString& aTitolo) {}
    QString titolo() const { return m_titoli[m_film]; }

public slots:
    void changeFilm();

signals:
    void fileSourceChanged();
    void domandaChanged();
    void titoloChanged();
    void appQuit();

private:
    int m_film;

    QList<QString> m_fileSources;
    QList<QString> m_domande;
    QList<QString> m_titoli;
};

#endif // FILMNAME_H
