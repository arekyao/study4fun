/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef HelloWorld_H
#define HelloWorld_H

#include <thrift/TDispatchProcessor.h>
#include "helloworld_types.h"



class HelloWorldIf {
 public:
  virtual ~HelloWorldIf() {}
  virtual void sayHello(std::string& _return) = 0;
};

class HelloWorldIfFactory {
 public:
  typedef HelloWorldIf Handler;

  virtual ~HelloWorldIfFactory() {}

  virtual HelloWorldIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(HelloWorldIf* /* handler */) = 0;
};

class HelloWorldIfSingletonFactory : virtual public HelloWorldIfFactory {
 public:
  HelloWorldIfSingletonFactory(const boost::shared_ptr<HelloWorldIf>& iface) : iface_(iface) {}
  virtual ~HelloWorldIfSingletonFactory() {}

  virtual HelloWorldIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(HelloWorldIf* /* handler */) {}

 protected:
  boost::shared_ptr<HelloWorldIf> iface_;
};

class HelloWorldNull : virtual public HelloWorldIf {
 public:
  virtual ~HelloWorldNull() {}
  void sayHello(std::string& /* _return */) {
    return;
  }
};


class HelloWorld_sayHello_args {
 public:

  HelloWorld_sayHello_args() {
  }

  virtual ~HelloWorld_sayHello_args() throw() {}


  bool operator == (const HelloWorld_sayHello_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const HelloWorld_sayHello_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const HelloWorld_sayHello_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class HelloWorld_sayHello_pargs {
 public:


  virtual ~HelloWorld_sayHello_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _HelloWorld_sayHello_result__isset {
  _HelloWorld_sayHello_result__isset() : success(false) {}
  bool success;
} _HelloWorld_sayHello_result__isset;

class HelloWorld_sayHello_result {
 public:

  HelloWorld_sayHello_result() : success() {
  }

  virtual ~HelloWorld_sayHello_result() throw() {}

  std::string success;

  _HelloWorld_sayHello_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const HelloWorld_sayHello_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const HelloWorld_sayHello_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const HelloWorld_sayHello_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _HelloWorld_sayHello_presult__isset {
  _HelloWorld_sayHello_presult__isset() : success(false) {}
  bool success;
} _HelloWorld_sayHello_presult__isset;

class HelloWorld_sayHello_presult {
 public:


  virtual ~HelloWorld_sayHello_presult() throw() {}

  std::string* success;

  _HelloWorld_sayHello_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class HelloWorldClient : virtual public HelloWorldIf {
 public:
  HelloWorldClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  HelloWorldClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void sayHello(std::string& _return);
  void send_sayHello();
  void recv_sayHello(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class HelloWorldProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<HelloWorldIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (HelloWorldProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_sayHello(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  HelloWorldProcessor(boost::shared_ptr<HelloWorldIf> iface) :
    iface_(iface) {
    processMap_["sayHello"] = &HelloWorldProcessor::process_sayHello;
  }

  virtual ~HelloWorldProcessor() {}
};

class HelloWorldProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  HelloWorldProcessorFactory(const ::boost::shared_ptr< HelloWorldIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< HelloWorldIfFactory > handlerFactory_;
};

class HelloWorldMultiface : virtual public HelloWorldIf {
 public:
  HelloWorldMultiface(std::vector<boost::shared_ptr<HelloWorldIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~HelloWorldMultiface() {}
 protected:
  std::vector<boost::shared_ptr<HelloWorldIf> > ifaces_;
  HelloWorldMultiface() {}
  void add(boost::shared_ptr<HelloWorldIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void sayHello(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sayHello(_return);
    }
    ifaces_[i]->sayHello(_return);
    return;
  }

};



#endif
