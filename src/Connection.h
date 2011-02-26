#include <QObject>
#include <QStringList>

class QTcpSocket;
class WebPage;
class Command;

class Connection : public QObject {
  Q_OBJECT

  public:
    Connection(QTcpSocket *socket, WebPage *page, QObject *parent = 0);

  public slots:
    void checkNext();
    void finishCommand(bool success, QString &response);

  private:
    void readNext();
    void processLine(const char *line);
    Command *createCommand(const char *name);
    void startCommand();
    void continueCommand(const char *line);

    QTcpSocket *m_socket;
    Command *m_command;
    QStringList m_arguments;
    int m_argumentsExpected;
    WebPage *m_page;
};
