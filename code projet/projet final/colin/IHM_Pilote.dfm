﻿object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 398
  ClientWidth = 849
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 575
    Top = 212
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 584
    Top = 27
    Width = 233
    Height = 25
    Caption = 'mettre en marche le tapis'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 391
    Top = 172
    Width = 75
    Height = 25
    Caption = 'allumer tapis'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 391
    Top = 230
    Width = 75
    Height = 25
    Caption = #233'teindre tapis'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 391
    Top = 277
    Width = 75
    Height = 25
    Caption = 'Button5'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 550
    Top = 252
    Width = 75
    Height = 25
    Caption = 'Button6'
    TabOrder = 5
    OnClick = Button6Click
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 8
    Width = 249
    Height = 128
    Caption = 'Connexion'
    TabOrder = 6
    object shpConnexion: TShape
      Left = 184
      Top = 48
      Width = 41
      Height = 35
    end
    object btnConnexion: TButton
      Left = 48
      Top = 80
      Width = 89
      Height = 25
      Caption = 'connexion'
      TabOrder = 0
      OnClick = btnConnexionClick
    end
    object edtIp: TEdit
      Left = 32
      Top = 21
      Width = 121
      Height = 21
      TabOrder = 1
      Text = '192.168.64.200'
    end
    object edtPort: TEdit
      Left = 32
      Top = 48
      Width = 121
      Height = 21
      TabOrder = 2
      Text = '502'
    end
  end
  object Action: TGroupBox
    Left = 287
    Top = 8
    Width = 280
    Height = 128
    Caption = 'Action'
    TabOrder = 7
    object btnActiveTapis: TButton
      Left = 71
      Top = 21
      Width = 137
      Height = 25
      Caption = 'activer lecture du tapis'
      TabOrder = 0
      OnClick = btnActiveTapisClick
    end
  end
  object btnDéconnexion: TButton
    Left = 64
    Top = 88
    Width = 89
    Height = 25
    Caption = 'd'#233'connexion'
    TabOrder = 8
    Visible = False
    OnClick = btnDéconnexionClick
  end
  object btnDesactiveTapis: TButton
    Left = 358
    Top = 60
    Width = 137
    Height = 25
    Caption = 'd'#233'sactiver lecture du tapis'
    TabOrder = 9
    OnClick = btnDesactiveTapisClick
  end
end
