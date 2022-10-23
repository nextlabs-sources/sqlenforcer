#include <memory>

#ifndef TASK_H
#define TASK_H

struct IResultSet;
struct ITask;
struct IFileIter;

struct IResultSet {
    virtual ~IResultSet() {}
    virtual bool compare_with(IResultSet *other) = 0;
	virtual const char* json_serialize()=0;
};

struct ITask {
    virtual ~ITask() {}
    virtual bool do_prepare() = 0;
    virtual unsigned int get_action_count() = 0;
    virtual std::shared_ptr<IResultSet> execute_by_index(unsigned int) = 0;
    virtual IResultSet *get_expect_result_set_by_index(unsigned int) = 0;
    virtual const char *get_task_name() = 0;
};

struct IFileIter {
    virtual ~IFileIter() {}
    virtual bool next() = 0;
    virtual const char * get_file_name() = 0;
    virtual const char * get_file_content() = 0;
};

ITask *make_task(const char *json_task,const char*name, const char*sqlpath);
void free_task(ITask *);

std::shared_ptr<IFileIter> make_file_iter(const char *directory_name);
void free_file_iter(IFileIter *);




#endif