object Form1: TForm1
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
    Left = 48
    Top = 180
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button5: TButton
    Left = 48
    Top = 211
    Width = 75
    Height = 25
    Caption = 'Button5'
    TabOrder = 1
    OnClick = Button5Click
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 8
    Width = 249
    Height = 128
    Caption = 'Connexion'
    TabOrder = 2
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
    Left = 286
    Top = 8
    Width = 280
    Height = 128
    Caption = 'Action'
    TabOrder = 3
    Visible = False
    object btnActiveTapis: TButton
      Left = 64
      Top = 35
      Width = 144
      Height = 25
      Caption = 'activer lecture du tapis'
      TabOrder = 0
      OnClick = btnActiveTapisClick
    end
    object btnDesactiveTapis: TButton
      Left = 64
      Top = 35
      Width = 145
      Height = 25
      Caption = 'd'#233'sactiver lecture du tapis'
      TabOrder = 1
      Visible = False
      OnClick = btnDesactiveTapisClick
    end
    object btnAllumerTapis: TButton
      Left = 64
      Top = 74
      Width = 145
      Height = 25
      Caption = 'allumer tapis'
      TabOrder = 2
      OnClick = btnAllumerTapisClick
    end
    object btnEteindreTapis: TButton
      Left = 64
      Top = 74
      Width = 145
      Height = 25
      Caption = #233'teindre tapis'
      TabOrder = 3
      Visible = False
      OnClick = btnEteindreTapisClick
    end
  end
  object btnDéconnexion: TButton
    Left = 64
    Top = 88
    Width = 89
    Height = 25
    Caption = 'd'#233'connexion'
    TabOrder = 4
    Visible = False
    OnClick = btnDéconnexionClick
  end
  object Button7: TButton
    Left = 48
    Top = 242
    Width = 75
    Height = 25
    Caption = 'Button7'
    TabOrder = 5
    OnClick = Button7Click
  end
  object Edit1: TEdit
    Left = 144
    Top = 244
    Width = 121
    Height = 21
    TabOrder = 6
    Text = 'Edit1'
  end
  object Memo1: TMemo
    Left = 640
    Top = 8
    Width = 201
    Height = 382
    ScrollBars = ssVertical
    TabOrder = 7
  end
end
