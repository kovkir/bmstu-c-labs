from tkinter import Entry, Label, Button, Tk, messagebox, END
import ctypes

lib = ctypes.CDLL('./lib/libfunc.so')

_fill_array = lib.fill_array
_fill_array.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_fill_array.restype = None

_add_elem_after_even = lib.add_elem_after_even
_add_elem_after_even.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int,
    ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int)
_add_elem_after_even.restype = ctypes.c_int

def fill_array(size):

    array = (ctypes.c_int * size)()
    _fill_array(array, size)

    return list(array)

def add_elem_after_even(arr, size_arr, size_res_arr, numb):

    arr = (ctypes.c_int * size_arr)(*arr)
    res_arr = (ctypes.c_int * size_res_arr)()

    numb_elem = _add_elem_after_even(arr, size_arr, res_arr, size_res_arr, numb)
    
    if (numb_elem > size_res_arr):
        res_arr = (ctypes.c_int * numb_elem)(*res_arr)
        _add_elem_after_even(arr, size_arr, res_arr, numb_elem, numb)

    return list(res_arr)

def arr_of_prime_numb():

    try:
        numb = int(entry_field_1.get())

    except:
        messagebox.showerror("Ошибка ввода", "Кол-во элементов массива - целое число!")
        return

    if (numb < 1):
        messagebox.showerror("Ошибка ввода", "Кол-во элементов массива должно быть больше 0!")
        return

    arr = fill_array(numb)
    str_arr = ' '.join(str(numb) for numb in arr)

    output_field_1.delete(0, END)
    output_field_1.insert(0, str_arr)

def insert_numb_into_arr():

    try:
        numb = int(entry_field_3.get())

    except:
        messagebox.showerror("Ошибка ввода", "Ошибка при воде вставляемого в массив числа!")
        return

    str_arr = entry_field_2.get()

    try:
        arr = [int(i) for i in str_arr.split()]

    except:
        messagebox.showerror("Ошибка ввода", "В введённом массиве присутствуют посторонние символы!")


    res_arr = add_elem_after_even(arr, len(arr), len(arr), numb)

    str_arr = ' '.join(str(numb) for numb in res_arr)

    output_field_2.delete(0, END)
    output_field_2.insert(0, str_arr)


window = Tk()
window['bg'] = 'light gray'
window.title('Lab_12')
window.geometry("400x430")

txt_input_1 = Label(window, text = 'Кол-во элементов массива:', bg = 'light gray',
    font = ('Courier New', 16))
txt_input_1.place(x = 20, y = 15, width = 270, height = 30)

entry_field_1 = Entry(window, width = 5, font = ('Courier New', 16))
entry_field_1.place(x = 300, y = 15, width = 70, height = 30)
entry_field_1.focus()    

btn_fill_array_1 = Button(window, text = 'Вывести массив из\n N простых чисел',
    font = ('Courier New', 16), activebackground = '#555555', command = arr_of_prime_numb)

btn_fill_array_1.place(x = 60, y = 60, width = 270, height = 45)

output_field_1 = Entry(window, width = 5, font = ('Courier New', 16))
output_field_1.place(x = 20, y = 120, width = 360, height = 30)

txt_input_2 = Label(window, text = 'Заполните массив', bg = 'light gray',
    font = ('Courier New', 16))
txt_input_2.place(x = 20, y = 170, width = 360, height = 30)

entry_field_2 = Entry(window, width = 35, font = ('Courier New', 16))
entry_field_2.place(x = 20, y = 205, width = 360, height = 30)

txt_input_3 = Label(window, text = 'Вставляемое в массив число:', bg = 'light gray',
    font = ('Courier New', 16))
txt_input_3.place(x = 20, y = 250, width = 270, height = 30)

entry_field_3 = Entry(window, width = 5, font = ('Courier New', 16))
entry_field_3.place(x = 300, y = 250, width = 70, height = 30)

btn_add_elem = Button(window, text = 'Добавить после каждого чётного\nэлемента указанное число',
    font = ('Courier New', 16), activebackground = '#555555', command = insert_numb_into_arr)

btn_add_elem.place(x = 20, y = 290, width = 360, height = 45)

txt_output = Label(window, text = 'Полученный массив:', bg = 'light gray',
    font = ('Courier New', 16))
txt_output.place(x = 20, y = 345, width = 360, height = 30)

output_field_2 = Entry(window, width = 5, font = ('Courier New', 16))
output_field_2.place(x = 20, y = 375, width = 360, height = 30)

window.mainloop()
