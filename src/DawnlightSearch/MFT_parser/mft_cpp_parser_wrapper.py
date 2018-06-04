from __future__ import absolute_import

try:
    from .._Global_logger import *
except:
    import logging

    logger = logging.getLogger()

import os

MFT_CPP_PARSER_PATH = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'mft_cpp_parser')


# def mft_parser_cpp(mft_filename, db_filename, table_name):
#     # ./mft_parser  "/home/cc/Documents/PycharmProjects/NTFS_index_search_tool/mft3" aaa.db table_uuid343
#     pass
#     import os, subprocess
#     cpp_paser_path = MFT_CPP_PARSER_PATH
#     procExe = subprocess.Popen([cpp_paser_path, mft_filename, db_filename, table_name],
#                                stdout=subprocess.PIPE, stderr=subprocess.PIPE,
#                                universal_newlines=True)
#     while procExe.poll() is None:
#         # print "procExe.poll(): ", procExe.poll()
#         line = procExe.stdout.readline()
#         logger.info("mft_parser_cpp: " + line)
#     if procExe.poll() == 0:
#         logger.info("mft_parser_cpp: Done.")
#     else:
#         logger.error("mft_parser_cpp: ERROR-- " + "".join(procExe.stderr.readlines()))

import multiprocessing

def parserProcess(mft_filename, db_filename, table_name):

    import DawnlightSearch.MFT_parser.mft_c_parser_module as mft_c_parser_module
    rst = mft_c_parser_module.mft_c_parser_func(mft_filename, db_filename, table_name)
    logger.info(rst)

def mft_parser_cpp(mft_filename, db_filename, table_name):
    # import time
    # print('parser sleep test')
    # time.sleep(10)
    # print('parser sleep test end')
    # return

    p = multiprocessing.Process(target=parserProcess, args=(mft_filename, db_filename, table_name))
    p.daemon = True
    p.start()
    p.join()
    logger.info('mft_parser_cpp END')