#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <QSharedPointer>

#define DECLARE_SHARED_PTR(type) typedef QSharedPointer<type> type ## Ptr;

template<class T>
class Singleton {
  Q_DISABLE_COPY(Timer)
public:
  getInstance() {
    if (m_ptrInstance.isNull()) {
      m_ptrInstance = QSharedPointer<T>(new T());
    }

    return m_singleton;
  }

protected:
  Singleton(){}
  virtual ~Singleton(){}

private:
  static QSharedPointer<T> m_ptrInstance;

};


template<class T> QSharedPointer<T> Singleton<T>::m_ptrInstance = QSharedPointer<t>(NULL);





#endif /* _SINGLETON_H_ */
