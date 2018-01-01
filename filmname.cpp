#include "filmname.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

FilmName::FilmName(const QString& filename, QObject *parent) :
    m_film(0),
    QObject(parent)
{
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);

        while (!stream.atEnd()) {
            QString line = stream.readLine();
//            if (line == "")
//                continue;
            QStringList items = line.split(";");
            //qDebug() << line;
            m_fileSources.append(items.at(0));
            m_titoli.append(items.at(1));
            int nDomande = items.at(2).toInt();
            QString d;
            for (int i=0; i<nDomande; i++) {
                d = d + QString::number(i+1) + ". " + items[3+i].replace("%", "\n") + "\n\n";
            }
            m_domande.append(d);
        }

        file.close();
    }
}

void FilmName::changeFilm()
{
    if (m_film == m_fileSources.size()-1) {
        emit appQuit();
        return;
    }

    m_film++;
    emit fileSourceChanged();
    emit domandaChanged();
    emit titoloChanged();
}
