object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 300
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 160
    Top = 40
    Width = 43
    Height = 41
    Brush.Color = clRed
  end
  object Button1: TButton
    Left = 56
    Top = 56
    Width = 75
    Height = 25
    Caption = 'connection'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 56
    Top = 104
    Width = 75
    Height = 25
    Caption = 'piston 1'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 152
    Top = 104
    Width = 75
    Height = 25
    Caption = 'piston 1'
    TabOrder = 2
    OnClick = Button3Click
  end
end
