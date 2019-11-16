import sys
import os
import subprocess


ACCEPTS = "accepts"
ERRORS = "errors"
TOTAL = "TOTAL"
W = 50
OK = '\U0001F60E'
KO = '\U0001F621'
RED = '\33[31m'
GRN = '\33[32m'
YLW = '\33[33m'
VLT = '\33[35m'
WHT = '\33[37m'


def is_executable_file(path: str):
    return True if os.path.exists(path) and os.access(path, os.X_OK) else False


def check_accepts(exe: str):
    accepts = os.listdir(ACCEPTS)
    success = 0
    for file in accepts:
        cmd = get_cmd(exe, ACCEPTS, file)
        output = subprocess.getoutput(cmd)[:5].upper()
        if output != "ERROR":
            print(f'{GRN} {file: <{W}} {OK}')
            success += 1
        else:
            print(f'{RED} {file: <{W}} {KO}')
    print(f'{YLW} {TOTAL: <{W}} {GRN}{success}{WHT}/{RED}{len(accepts) - success}{WHT}')


def get_cmd(exe: str, path: str, file: str):
    if len(exe) > 3 and exe[-3:] == ".py":
        return f'python3 {exe} < {path}/{file}'
    return f'./{exe} < {path}/{file}'


def check_errors(exe: str):
    errors = os.listdir(ERRORS)
    success = 0
    for file in errors:
        cmd = get_cmd(exe, ERRORS, file)
        output = subprocess.getoutput(cmd)[:5].upper()
        if output == "ERROR":
            print(f'{GRN} {file: <{W}} {OK}')
            success += 1
        else:
            print(f'{RED} {file: <{W}} {KO}')
    print(f'{YLW} {TOTAL: <{W}} {GRN}{success}{WHT}/{RED}{len(errors) - success}{WHT}')


def checking():
    for exe in sys.argv[1:]:
        if is_executable_file(exe):
            print(f'\n{VLT}{exe} < {ACCEPTS}\\')
            check_accepts(exe)
            print(f'\n{VLT}{exe} < {ERRORS}\\')
            check_errors(exe)
        else:
            print(f'\n{WHT}file: {RED}{exe} {YLW}is exists: {WHT}{is_executable_file(exe)}\n')


checking()

