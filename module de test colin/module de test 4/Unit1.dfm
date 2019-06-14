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
    Top = 56
    Width = 49
    Height = 41
  end
  object Label1: TLabel
    Left = 232
    Top = 168
    Width = 149
    Height = 13
    Caption = 'indiquer le num'#233'ro de la caisse '
  end
  object Button1: TButton
    Left = 64
    Top = 64
    Width = 75
    Height = 25
    Caption = 'connexion'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 376
    Top = 191
    Width = 97
    Height = 25
    Caption = 'valider la caisse'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 240
    Top = 193
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object Button3: TButton
    Left = 312
    Top = 64
    Width = 97
    Height = 25
    Caption = 'Activer tapis'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 312
    Top = 95
    Width = 97
    Height = 25
    Caption = 'Etteindre tapis'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 232
    Top = 247
    Width = 129
    Height = 25
    Caption = 'sortir m'#233'dicament'
    TabOrder = 5
    OnClick = Button5Click
  end
end
