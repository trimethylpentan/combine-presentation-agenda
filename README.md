# Combine Presentation Agenda

This project generates an agenda as png file from a textbased input-file.

## Run

To run the program, you need to create a `index.txt` in the same folder the binary is located. Second, you need a directory named `img`
in the same directory. This directory must include:
- a `point_neutral.png`
- a `point_highlight.png`
- the icons you want to use

The `index.txt` file contains a list of icons you want to add. This list must equal the filenames of the icons in your `img` directory.

For example:
```
start.png
step2.png
step3.png
end.png
```

A working example can be found in `./files`

## Building

This project depends on [openCV](https://opencv.org/) which needs to be installed before building. Follow the steps in their 
[documentation](https://docs.opencv.org/master/df/d65/tutorial_table_of_content_introduction.html).

Next, you can compile this project using `Cmake` and `gcc`.

## Disclaimer
This project comes with absolutely no warranty and is far from being polished. It's just a simple program I needed. ;)
