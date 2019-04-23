object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 136
  ClientWidth = 490
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label_CodeBarre: TLabel
    Left = 120
    Top = 40
    Width = 54
    Height = 13
    Caption = 'Code Barre'
  end
  object Label_MessageErreur: TLabel
    Left = 24
    Top = 88
    Width = 444
    Height = 18
    Caption = 
      'Le lecteur code barre n'#39'est pas d'#233't'#233'ct'#233', veuillez v'#233'rifier la co' +
      'nnexion'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Groupe_CodeBarre: TGroupBox
    Left = 104
    Top = 24
    Width = 257
    Height = 49
    TabOrder = 0
  end
  object Edit_CodeBarre: TEdit
    Left = 232
    Top = 37
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Thread_LecteurCodeBarre: TIdThreadComponent
    Active = True
    Loop = True
    Priority = tpNormal
    StopMode = smTerminate
    OnAfterRun = Thread_LecteurCodeBarreAfterRun
    OnBeforeRun = Thread_LecteurCodeBarreBeforeRun
    OnRun = Thread_LecteurCodeBarreRun
    Left = 384
    Top = 32
  end
end
